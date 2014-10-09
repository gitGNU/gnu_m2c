/* Run-time functions for Modula-2 coroutine implementation.
 * Copyright 1993, 1994, 1995, 1996, 1997 Vladimir Makarov
 * This file is part of m2c.
 *
 * m2c is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * m2c is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with m2c. If not, see <http://www.gnu.org/licenses/>.
 */

#include <ucontext.h>
#include <stdio.h>
#include "m2lib.h"

static ucontext_t *
prepare_context (void)
{
  ucontext_t *ctx;
  int err;

  ctx = malloc(sizeof(ucontext_t));
  if (!ctx)
    {
      fputs("\nno memory for coroutine context", stderr);
      m2_halt();
    }

  err = getcontext(ctx);
  if (err != 0)
    {
      fputs("\ngetcontext failed", stderr);
      m2_halt();
    }

  return ctx;
}

void
m2_newprocess (void (*f) (), int *sp, unsigned int size, int **cor)
{
  ucontext_t *ctx = prepare_context();
  ctx->uc_stack.ss_sp = sp;
  ctx->uc_stack.ss_size = size;
  ctx->uc_stack.ss_flags = 0;
  ctx->uc_link = 0;
  makecontext(ctx, f, 0);
  *cor = (void *) ctx;
}

void
m2_transfer (int **cor1, int **cor2)
{
  int err;

  if (!*cor1)
    *cor1 = (void *) prepare_context();

  err = swapcontext((void *) *cor1, (void *) *cor2);
  if (err != 0)
    {
      fputs("\nswapcontext failed", stderr);
      m2_halt();
    }
}

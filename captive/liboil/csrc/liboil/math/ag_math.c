/* This file is autogenerated.  Do not edit. */
/*
 * LIBOIL - Library of Optimized Inner Loops
 * Copyright (c) 2005 David A. Schleef <ds.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <math.h>

#include <liboil/liboil.h>
#include <liboil/liboilclasses.h>

static void
add_f32_pointer (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  while (n) {
    *dest = *src1 + *src2;
    dest++;
    src1++;
    src2++;
    n--;
  }
}
OIL_DEFINE_IMPL (add_f32_pointer, add_f32);

static void
add_f32_unroll2 (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  if (n & 1) {
    dest[0] = src1[0] + src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=2){
    dest[i] = src1[i] + src2[i];
    dest[i+1] = src1[i+1] + src2[i+1];
  }
}
OIL_DEFINE_IMPL (add_f32_unroll2, add_f32);

static void
add_f32_unroll4a (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  while (n & 3) {
    dest[0] = src1[0] + src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=4){
    dest[i] = src1[i] + src2[i];
    dest[i+1] = src1[i+1] + src2[i+1];
    dest[i+2] = src1[i+2] + src2[i+2];
    dest[i+3] = src1[i+3] + src2[i+3];
  }
}
OIL_DEFINE_IMPL (add_f32_unroll4a, add_f32);

static void
add_f32_unroll4b (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    dest[i+0] = src1[i+0] + src2[i+0];
    dest[i+1] = src1[i+1] + src2[i+1];
    dest[i+2] = src1[i+2] + src2[i+2];
    dest[i+3] = src1[i+3] + src2[i+3];
  }
  for(;i<n;i++){
    dest[i] = src1[i] + src2[i];
  }
}
OIL_DEFINE_IMPL (add_f32_unroll4b, add_f32);

static void
add_f32_unroll4c (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    *dest++ = *src1++ + *src2++;
    *dest++ = *src1++ + *src2++;
    *dest++ = *src1++ + *src2++;
    *dest++ = *src1++ + *src2++;
  }
  for(;i<n;i++){
    *dest++ = *src1++ + *src2++;
  }
}
OIL_DEFINE_IMPL (add_f32_unroll4c, add_f32);

static void
add_f64_pointer (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  while (n) {
    *dest = *src1 + *src2;
    dest++;
    src1++;
    src2++;
    n--;
  }
}
OIL_DEFINE_IMPL (add_f64_pointer, add_f64);

static void
add_f64_unroll2 (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  if (n & 1) {
    dest[0] = src1[0] + src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=2){
    dest[i] = src1[i] + src2[i];
    dest[i+1] = src1[i+1] + src2[i+1];
  }
}
OIL_DEFINE_IMPL (add_f64_unroll2, add_f64);

static void
add_f64_unroll4a (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  while (n & 3) {
    dest[0] = src1[0] + src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=4){
    dest[i] = src1[i] + src2[i];
    dest[i+1] = src1[i+1] + src2[i+1];
    dest[i+2] = src1[i+2] + src2[i+2];
    dest[i+3] = src1[i+3] + src2[i+3];
  }
}
OIL_DEFINE_IMPL (add_f64_unroll4a, add_f64);

static void
add_f64_unroll4b (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    dest[i+0] = src1[i+0] + src2[i+0];
    dest[i+1] = src1[i+1] + src2[i+1];
    dest[i+2] = src1[i+2] + src2[i+2];
    dest[i+3] = src1[i+3] + src2[i+3];
  }
  for(;i<n;i++){
    dest[i] = src1[i] + src2[i];
  }
}
OIL_DEFINE_IMPL (add_f64_unroll4b, add_f64);

static void
add_f64_unroll4c (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    *dest++ = *src1++ + *src2++;
    *dest++ = *src1++ + *src2++;
    *dest++ = *src1++ + *src2++;
    *dest++ = *src1++ + *src2++;
  }
  for(;i<n;i++){
    *dest++ = *src1++ + *src2++;
  }
}
OIL_DEFINE_IMPL (add_f64_unroll4c, add_f64);

static void
subtract_f32_pointer (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  while (n) {
    *dest = *src1 - *src2;
    dest++;
    src1++;
    src2++;
    n--;
  }
}
OIL_DEFINE_IMPL (subtract_f32_pointer, subtract_f32);

static void
subtract_f32_unroll2 (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  if (n & 1) {
    dest[0] = src1[0] - src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=2){
    dest[i] = src1[i] - src2[i];
    dest[i+1] = src1[i+1] - src2[i+1];
  }
}
OIL_DEFINE_IMPL (subtract_f32_unroll2, subtract_f32);

static void
subtract_f32_unroll4a (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  while (n & 3) {
    dest[0] = src1[0] - src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=4){
    dest[i] = src1[i] - src2[i];
    dest[i+1] = src1[i+1] - src2[i+1];
    dest[i+2] = src1[i+2] - src2[i+2];
    dest[i+3] = src1[i+3] - src2[i+3];
  }
}
OIL_DEFINE_IMPL (subtract_f32_unroll4a, subtract_f32);

static void
subtract_f32_unroll4b (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    dest[i+0] = src1[i+0] - src2[i+0];
    dest[i+1] = src1[i+1] - src2[i+1];
    dest[i+2] = src1[i+2] - src2[i+2];
    dest[i+3] = src1[i+3] - src2[i+3];
  }
  for(;i<n;i++){
    dest[i] = src1[i] - src2[i];
  }
}
OIL_DEFINE_IMPL (subtract_f32_unroll4b, subtract_f32);

static void
subtract_f32_unroll4c (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    *dest++ = *src1++ - *src2++;
    *dest++ = *src1++ - *src2++;
    *dest++ = *src1++ - *src2++;
    *dest++ = *src1++ - *src2++;
  }
  for(;i<n;i++){
    *dest++ = *src1++ - *src2++;
  }
}
OIL_DEFINE_IMPL (subtract_f32_unroll4c, subtract_f32);

static void
subtract_f64_pointer (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  while (n) {
    *dest = *src1 - *src2;
    dest++;
    src1++;
    src2++;
    n--;
  }
}
OIL_DEFINE_IMPL (subtract_f64_pointer, subtract_f64);

static void
subtract_f64_unroll2 (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  if (n & 1) {
    dest[0] = src1[0] - src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=2){
    dest[i] = src1[i] - src2[i];
    dest[i+1] = src1[i+1] - src2[i+1];
  }
}
OIL_DEFINE_IMPL (subtract_f64_unroll2, subtract_f64);

static void
subtract_f64_unroll4a (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  while (n & 3) {
    dest[0] = src1[0] - src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=4){
    dest[i] = src1[i] - src2[i];
    dest[i+1] = src1[i+1] - src2[i+1];
    dest[i+2] = src1[i+2] - src2[i+2];
    dest[i+3] = src1[i+3] - src2[i+3];
  }
}
OIL_DEFINE_IMPL (subtract_f64_unroll4a, subtract_f64);

static void
subtract_f64_unroll4b (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    dest[i+0] = src1[i+0] - src2[i+0];
    dest[i+1] = src1[i+1] - src2[i+1];
    dest[i+2] = src1[i+2] - src2[i+2];
    dest[i+3] = src1[i+3] - src2[i+3];
  }
  for(;i<n;i++){
    dest[i] = src1[i] - src2[i];
  }
}
OIL_DEFINE_IMPL (subtract_f64_unroll4b, subtract_f64);

static void
subtract_f64_unroll4c (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    *dest++ = *src1++ - *src2++;
    *dest++ = *src1++ - *src2++;
    *dest++ = *src1++ - *src2++;
    *dest++ = *src1++ - *src2++;
  }
  for(;i<n;i++){
    *dest++ = *src1++ - *src2++;
  }
}
OIL_DEFINE_IMPL (subtract_f64_unroll4c, subtract_f64);

static void
divide_f32_pointer (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  while (n) {
    *dest = *src1 / *src2;
    dest++;
    src1++;
    src2++;
    n--;
  }
}
OIL_DEFINE_IMPL (divide_f32_pointer, divide_f32);

static void
divide_f32_unroll2 (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  if (n & 1) {
    dest[0] = src1[0] / src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=2){
    dest[i] = src1[i] / src2[i];
    dest[i+1] = src1[i+1] / src2[i+1];
  }
}
OIL_DEFINE_IMPL (divide_f32_unroll2, divide_f32);

static void
divide_f32_unroll4a (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  while (n & 3) {
    dest[0] = src1[0] / src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=4){
    dest[i] = src1[i] / src2[i];
    dest[i+1] = src1[i+1] / src2[i+1];
    dest[i+2] = src1[i+2] / src2[i+2];
    dest[i+3] = src1[i+3] / src2[i+3];
  }
}
OIL_DEFINE_IMPL (divide_f32_unroll4a, divide_f32);

static void
divide_f32_unroll4b (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    dest[i+0] = src1[i+0] / src2[i+0];
    dest[i+1] = src1[i+1] / src2[i+1];
    dest[i+2] = src1[i+2] / src2[i+2];
    dest[i+3] = src1[i+3] / src2[i+3];
  }
  for(;i<n;i++){
    dest[i] = src1[i] / src2[i];
  }
}
OIL_DEFINE_IMPL (divide_f32_unroll4b, divide_f32);

static void
divide_f32_unroll4c (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    *dest++ = *src1++ / *src2++;
    *dest++ = *src1++ / *src2++;
    *dest++ = *src1++ / *src2++;
    *dest++ = *src1++ / *src2++;
  }
  for(;i<n;i++){
    *dest++ = *src1++ / *src2++;
  }
}
OIL_DEFINE_IMPL (divide_f32_unroll4c, divide_f32);

static void
divide_f64_pointer (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  while (n) {
    *dest = *src1 / *src2;
    dest++;
    src1++;
    src2++;
    n--;
  }
}
OIL_DEFINE_IMPL (divide_f64_pointer, divide_f64);

static void
divide_f64_unroll2 (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  if (n & 1) {
    dest[0] = src1[0] / src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=2){
    dest[i] = src1[i] / src2[i];
    dest[i+1] = src1[i+1] / src2[i+1];
  }
}
OIL_DEFINE_IMPL (divide_f64_unroll2, divide_f64);

static void
divide_f64_unroll4a (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  while (n & 3) {
    dest[0] = src1[0] / src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=4){
    dest[i] = src1[i] / src2[i];
    dest[i+1] = src1[i+1] / src2[i+1];
    dest[i+2] = src1[i+2] / src2[i+2];
    dest[i+3] = src1[i+3] / src2[i+3];
  }
}
OIL_DEFINE_IMPL (divide_f64_unroll4a, divide_f64);

static void
divide_f64_unroll4b (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    dest[i+0] = src1[i+0] / src2[i+0];
    dest[i+1] = src1[i+1] / src2[i+1];
    dest[i+2] = src1[i+2] / src2[i+2];
    dest[i+3] = src1[i+3] / src2[i+3];
  }
  for(;i<n;i++){
    dest[i] = src1[i] / src2[i];
  }
}
OIL_DEFINE_IMPL (divide_f64_unroll4b, divide_f64);

static void
divide_f64_unroll4c (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    *dest++ = *src1++ / *src2++;
    *dest++ = *src1++ / *src2++;
    *dest++ = *src1++ / *src2++;
    *dest++ = *src1++ / *src2++;
  }
  for(;i<n;i++){
    *dest++ = *src1++ / *src2++;
  }
}
OIL_DEFINE_IMPL (divide_f64_unroll4c, divide_f64);

static void
multiply_f32_pointer (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  while (n) {
    *dest = *src1 * *src2;
    dest++;
    src1++;
    src2++;
    n--;
  }
}
OIL_DEFINE_IMPL (multiply_f32_pointer, multiply_f32);

static void
multiply_f32_unroll2 (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  if (n & 1) {
    dest[0] = src1[0] * src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=2){
    dest[i] = src1[i] * src2[i];
    dest[i+1] = src1[i+1] * src2[i+1];
  }
}
OIL_DEFINE_IMPL (multiply_f32_unroll2, multiply_f32);

static void
multiply_f32_unroll4a (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  while (n & 3) {
    dest[0] = src1[0] * src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=4){
    dest[i] = src1[i] * src2[i];
    dest[i+1] = src1[i+1] * src2[i+1];
    dest[i+2] = src1[i+2] * src2[i+2];
    dest[i+3] = src1[i+3] * src2[i+3];
  }
}
OIL_DEFINE_IMPL (multiply_f32_unroll4a, multiply_f32);

static void
multiply_f32_unroll4b (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    dest[i+0] = src1[i+0] * src2[i+0];
    dest[i+1] = src1[i+1] * src2[i+1];
    dest[i+2] = src1[i+2] * src2[i+2];
    dest[i+3] = src1[i+3] * src2[i+3];
  }
  for(;i<n;i++){
    dest[i] = src1[i] * src2[i];
  }
}
OIL_DEFINE_IMPL (multiply_f32_unroll4b, multiply_f32);

static void
multiply_f32_unroll4c (oil_type_f32 *dest, oil_type_f32 *src1, oil_type_f32 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    *dest++ = *src1++ * *src2++;
    *dest++ = *src1++ * *src2++;
    *dest++ = *src1++ * *src2++;
    *dest++ = *src1++ * *src2++;
  }
  for(;i<n;i++){
    *dest++ = *src1++ * *src2++;
  }
}
OIL_DEFINE_IMPL (multiply_f32_unroll4c, multiply_f32);

static void
multiply_f64_pointer (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  while (n) {
    *dest = *src1 * *src2;
    dest++;
    src1++;
    src2++;
    n--;
  }
}
OIL_DEFINE_IMPL (multiply_f64_pointer, multiply_f64);

static void
multiply_f64_unroll2 (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  if (n & 1) {
    dest[0] = src1[0] * src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=2){
    dest[i] = src1[i] * src2[i];
    dest[i+1] = src1[i+1] * src2[i+1];
  }
}
OIL_DEFINE_IMPL (multiply_f64_unroll2, multiply_f64);

static void
multiply_f64_unroll4a (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  while (n & 3) {
    dest[0] = src1[0] * src2[0];
    dest++;
    src1++;
    src2++;
    n--;
  }
  for(i=0;i<n;i+=4){
    dest[i] = src1[i] * src2[i];
    dest[i+1] = src1[i+1] * src2[i+1];
    dest[i+2] = src1[i+2] * src2[i+2];
    dest[i+3] = src1[i+3] * src2[i+3];
  }
}
OIL_DEFINE_IMPL (multiply_f64_unroll4a, multiply_f64);

static void
multiply_f64_unroll4b (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    dest[i+0] = src1[i+0] * src2[i+0];
    dest[i+1] = src1[i+1] * src2[i+1];
    dest[i+2] = src1[i+2] * src2[i+2];
    dest[i+3] = src1[i+3] * src2[i+3];
  }
  for(;i<n;i++){
    dest[i] = src1[i] * src2[i];
  }
}
OIL_DEFINE_IMPL (multiply_f64_unroll4b, multiply_f64);

static void
multiply_f64_unroll4c (oil_type_f64 *dest, oil_type_f64 *src1, oil_type_f64 *src2, int n)
{
  int i;

  for(i=0;i<(n&(~0x3));i+=4){
    *dest++ = *src1++ * *src2++;
    *dest++ = *src1++ * *src2++;
    *dest++ = *src1++ * *src2++;
    *dest++ = *src1++ * *src2++;
  }
  for(;i<n;i++){
    *dest++ = *src1++ * *src2++;
  }
}
OIL_DEFINE_IMPL (multiply_f64_unroll4c, multiply_f64);


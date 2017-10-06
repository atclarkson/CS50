# Questions

## What's `stdint.h`?

An includes file that contains exact width data types.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The exact bit size of each data type is predefines so no more and not less memory will be a used for that particular data type.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

1, 4, 4 and 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

Ascii B and m

## What's the difference between `bfSize` and `biSize`?

bfSize is the size of the entire Bitmap include the header. biSize is only the size of the header.

## What does it mean if `biHeight` is negative?

The image scans top down when reading and displaying the pixels

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biClrUsed

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

If the file does not excist

## Why is the third argument to `fread` always `1` in our code?

It only reads 1 byte at a time

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?

Moves the File Insertion point to a specified location in the file.

## What is `SEEK_CUR`?

Moves the file insertion point relative to the current position

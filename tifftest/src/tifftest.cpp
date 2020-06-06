/*-----------------------------------------------------------------------------
* File Name: tifftest.cpp
* Purpose:
* Creation Date: 06-06-2020
* Last Modified: Sat 06 Jun 2020 09:54:06 AM MSK
* Created by: dima
-----------------------------------------------------------------------------*/

#include <stdio.h>
#include <tiffio.h>

int main(int argc, char* argv[]) {
    TIFF* tiff;
    tiff = TIFFOpen(argv[1], "r");
    TIFFClose(tiff);
    return 0;
}

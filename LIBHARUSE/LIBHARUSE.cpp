// LIBHARUSE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hpdf.h"




void error_handler(HPDF_STATUS error_no, HPDF_STATUS detail_no, void *user_data)
{
	printf("ERROR: error_no=%04X, detail_no=%d\n",
		(unsigned int)error_no, (int)detail_no);
}

int _tmain(int argc, _TCHAR* argv[])
{
	HPDF_Doc   Pdf = HPDF_New(error_handler, NULL);
	HPDF_Page  Page = HPDF_AddPage(Pdf);

	HPDF_Image MyImage = HPDF_LoadPngImageFromFile(Pdf, "C:\\temp\\Document-2020-06-10T18-37-32N2\\page-1.bmp");
	HPDF_REAL  Width = HPDF_Image_GetWidth(MyImage);
	HPDF_REAL  Height = HPDF_Image_GetHeight(MyImage);

	HPDF_Page_DrawImage(Page, MyImage, 5, 5, Width, Height);
	HPDF_SaveToFile(Pdf, "C:\\temp\\test.pdf");
	return 0;
}


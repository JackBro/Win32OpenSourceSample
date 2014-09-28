// libxlsEx.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#if defined (__cplusplus)
extern "C" {
#endif


#include "libxls/xls.h"

#if defined (__cplusplus)
}
#endif

#pragma comment(lib, "libxls.lib")

int main(int argc, char *argv[])
{
	xlsWorkBook* pWB;
	xlsWorkSheet* pWS;
	st_row_data* row;
	WORD t, tt;
	
//�׼� ������ ����.
	pWB = xls_open("test.xls", "UTF-8");	

	if (pWB != NULL)
	{		
//��ũ ��Ʈ ������ŭ ������ ����.
		for (int i = 0; i<pWB->sheets.count; i++) 
		{
			printf("Sheet[%i] (%s) pos=%i\n", i, pWB->sheets.sheet[i].name, pWB->sheets.sheet[i].filepos);

//��ũ ��Ʈ�� ���� ��
//�����͸� �Ľ��Ѵ�.
			pWS = xls_getWorkSheet(pWB, i);

			xls_parseWorkSheet(pWS);

//��ũ ��Ʈ�� ������ ����Ѵ�.
			printf("Count of rows: %i\n", pWS->rows.lastrow + 1);
			printf("Max col: %i\n", pWS->rows.lastcol);

			for (t = 0; t <= pWS->rows.lastrow; t++)
			{
				row = (st_row_data*)&pWS->rows.row[t];
				
				//xls_showROW(row);

				for (tt = 0; tt <= pWS->rows.lastcol; tt++)
				{
					st_cell_data cell = row->cells.cell[tt];
					printf("cell=%s\n", cell.str);

					//xls_showCell((st_cell_data *)&row->cells.cell[tt]);
				}
			}

		}
		//xls_showBookInfo(pWB);
	}
	
	return 0;
}
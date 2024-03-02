#include "../vendor/uefi.h"

EFI_STATUS
EfiMain(EFI_HANDLE handle, EFI_SYSTEM_TABLE* sys_table)
{
	EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL* con_out = sys_table->ConOut;

	if (con_out != 0)
	{
		for (;;)
		{
			con_out->Reset(con_out, FALSE);
			con_out->OutputString(con_out, L"Hello World");
		}
	}

	return EFI_SUCCESS;
}

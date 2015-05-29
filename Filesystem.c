BOOL fs1()
{
 /*
 writes secret data to a file and checks it back
 */
 char buff[65535];
 char DataBuffer[] = "Dear AV, what is happiness ?";
DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
DWORD dwBytesWritten = 0;
BOOL bErrorFlag = FALSE;
 HANDLE hFile;
 DWORD dwBytesRead = 0;
char ReadBuffer[256] = {0};
 GetEnvironmentVariable("TMP", &buff[0], 65535);
 strcat_s(buff, "\\dull.txt");
 hFile = CreateFile(buff, GENERIC_WRITE, 0, NULL, CREATE_NEW,
FILE_ATTRIBUTE_NORMAL, NULL);
 bErrorFlag = WriteFile(hFile, DataBuffer, dwBytesToWrite,
&dwBytesWritten, NULL);
 CloseHandle(hFile);
 hFile = CreateFile(buff, GENERIC_READ, FILE_SHARE_READ, NULL,
OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
 ReadFile(hFile, ReadBuffer, 256-1, &dwBytesRead, NULL);
 CloseHandle(hFile);
 if(strstr(ReadBuffer,DataBuffer)){
 return FALSE;
 }
 return TRUE;
}

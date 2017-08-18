#include <windows.h>
#include <string.h>
#include<ctype.h>

void SetKey(BOOL bState, unsigned int keyCode) {
  BYTE keyState[256];
  INPUT input[2];

  GetKeyboardState((LPBYTE) & keyState);
  if ((bState && !(keyState[keyCode] & 1)) ||
    (!bState && (keyState[keyCode] & 1))) {
    ZeroMemory(input, sizeof(input));
    input[0].type = input[1].type = INPUT_KEYBOARD;
    input[0].ki.wVk = input[1].ki.wVk = keyCode;
    input[1].ki.dwFlags = KEYEVENTF_KEYUP;

    // Simulate a key input
    SendInput(2, input, sizeof(INPUT));
  }
}

//main entry
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
  BOOL bState;
  if (lstrlen(lpCmdLine) > 0) {
    bState = FALSE;
  } else {
    bState = TRUE;
  }

  //get self path
  char selfName[MAX_PATH];
  GetModuleFileName(NULL, selfName, MAX_PATH);

  //get file name from path
  const char * ptr = strrchr(selfName, '\\');
  if (ptr != NULL)
    strcpy(selfName, ptr + 1);

  //convert file name to lower case
  for (unsigned int i = 0; i < lstrlen(selfName); i++)
    selfName[i] = tolower(selfName[i]);
  //MessageBox(NULL, selfName, NULL, MB_OK|MB_ICONINFORMATION);

  if (strstr(selfName, "off") || strstr(selfName, "un"))
    bState = !bState;
  if (strstr(selfName, "num"))
    SetKey(bState, VK_NUMLOCK);
  if (strstr(selfName, "caps") || strstr(selfName, "capital"))
    SetKey(bState, VK_CAPITAL);
  if (strstr(selfName, "scro") || strstr(selfName, "scrl"))
    SetKey(bState, VK_SCROLL);

  return 0;
}

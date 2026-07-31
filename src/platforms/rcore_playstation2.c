#include "raylib.h"

#include <math.h>
#include <stdio.h>

void PS2_Log(int msg_type, const char *fmt, va_list va) {
  char buffer[1024] = {0};
  vsnprintf(buffer, sizeof buffer, fmt, va);
  buffer[sizeof buffer - 1] = '\0';

  switch (msg_type) {
  case LOG_TRACE:
    printf("[EE][TRACE]: %s\n", buffer);
    break;
  case LOG_DEBUG:
    printf("[EE][DEBUG]: %s\n", buffer);
    break;
  case LOG_INFO:
    printf("[EE][INFO]: %s\n", buffer);
    break;
  case LOG_WARNING:
    printf("[EE][WARNING]: %s\n", buffer);
    break;
  case LOG_ERROR:
    printf("[EE][ERROR]: %s\n", buffer);
    break;
  case LOG_FATAL:
    printf("[EE][FATAL]: %s\n", buffer);
    break;
  default:
    break;
  }
}

int    g_BlankDivisor = 1;
double g_RefreshHZ    = 59.94;

static inline void PS2_SetRefreshHZ(bool pal)
{
    g_RefreshHZ = pal ? 50.0 : 59.94;
}

void PS2_SetTargetFPS(int fps)
{
    if (fps <= 0 || fps >= (int)(g_RefreshHZ/(double)fps))
    {
        g_BlankDivisor = 1;
    }
    else
    {
        int div = (int)lround(g_RefreshHZ = (double)fps);
        if (div < 1) div = 1;
        g_BlankDivisor = div;
    }

}

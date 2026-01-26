#include "common/ipc_defs.h"
#include <coreinit/cache.h>
#include <coreinit/debug.h>
#include <coreinit/ios.h>
#include <coreinit/thread.h>
#include <cstdio>
#include <cstring>
#include <mocha/commands.h>

int main(int argc, char **argv) {

    // When the kernel exploit is set up successfully, we signal the ios to move on.
    int mcpFd = IOS_Open("/dev/mcp", (IOSOpenMode) 0);
    if (mcpFd >= 0) {
        int in  = IPC_CUSTOM_MEN_RPX_HOOK_COMPLETED;
        int out = 0;
        IOS_Ioctl(mcpFd, 100, &in, sizeof(in), &out, sizeof(out));

    }
    return 0;
}

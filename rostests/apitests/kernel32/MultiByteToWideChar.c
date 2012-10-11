/*
 * PROJECT:         ReactOS api tests
 * LICENSE:         GPLv2+ - See COPYING in the top level directory
 * PURPOSE:         Test for MultiByteToWideChar
 * PROGRAMMER:      Mike "tamlin" Nordell
 */

#include <windows.h>
#include <stdio.h>
#include <wine/test.h>


START_TEST(MultiByteToWideChar)
{
    int ret;

    ret = MultiByteToWideChar(CP_UTF8, 0, "a", sizeof("a"), 0, 0);
    ok(ret == 2, "ret should be 2, is %d\n", ret);

    ret = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, "a", sizeof("a"), 0, 0);
    ok(ret == 2, "ret should be 2, is %d\n", ret);
}
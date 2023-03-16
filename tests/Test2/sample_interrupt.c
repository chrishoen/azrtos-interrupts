/**************************************************************************/
/*                                                                        */
/*       Copyright (c) Microsoft Corporation. All rights reserved.        */
/*                                                                        */
/*       This software is licensed under the Microsoft Software License   */
/*       Terms for Microsoft Azure RTOS. Full text of the license can be  */
/*       found in the LICENSE file at https://aka.ms/AzureRTOS_EULA       */
/*       and in the root directory of this software.                      */
/*                                                                        */
/**************************************************************************/
#pragma warning(disable:4201)   // nameless struct/union
#pragma warning(disable:4127)   // conditional expression is constant

#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

#include "tx_api.h"

#pragma warning(disable:6387)

//******************************************************************************
//******************************************************************************
//******************************************************************************

inline void delay(int aLoop)
{
    volatile int gDummy = 0;
    for (int i = 0; i < aLoop; i++) gDummy++;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

HANDLE       _sample_win32_interrupt_handle;
DWORD        _sample_win32_interrupt_id;
DWORD WINAPI _sample_win32_interrupt_thread(LPVOID);

DWORD WINAPI _sample_win32_interrupt_thread(LPVOID* ptr)
{
    printf("_sample_win32_interrupt_thread IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");

    LARGE_INTEGER tPerformanceCount;
    QueryPerformanceCounter(&tPerformanceCount);
    srand((unsigned)(tPerformanceCount.LowPart & 0xffffffff));

    while (1)
    {
        /* Sleep for a random time, 250..350 ms. */
        int tSleep = 250 + (rand() % 100);
        Sleep(tSleep);
        printf("_sample_win32_interrupt_thread JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ\n");

        /* Call ThreadX context save for interrupt preparation.  */
        _tx_thread_context_save();

        /* Call application ISR here!  */
        delay(50000);

        /* Call ThreadX context restore for interrupt completion.  */
        _tx_thread_context_restore();
    }
}

DWORD WINAPI _sample_win32_interrupt_thread22(LPVOID* ptr)
{
    printf("_sample_win32_interrupt_thread IIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIIII\n");

    LARGE_INTEGER tPerformanceCount;
    QueryPerformanceCounter(&tPerformanceCount);
    srand((unsigned)(tPerformanceCount.LowPart & 0xffffffff));

    while (1)
    {
        /* Sleep for a random time, 250..350 ms. */
        int tSleep = 250 + (rand() % 100);
        Sleep(tSleep);

        /* Call ThreadX context save for interrupt preparation.  */
        _tx_thread_context_save();

        /* Call application ISR here!  */
        printf("_sample_win32_interrupt_thread JJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJJ\n");

        /* Call ThreadX context restore for interrupt completion.  */
        _tx_thread_context_restore();
    }
}

BOOL sample_interrupt_start()
{
    _sample_win32_interrupt_handle =
        CreateThread(NULL, 0, _sample_win32_interrupt_thread, (LPVOID)&_sample_win32_interrupt_handle,
            CREATE_SUSPENDED, &_sample_win32_interrupt_id);

    SetThreadPriority(_sample_win32_interrupt_handle, THREAD_PRIORITY_BELOW_NORMAL);

    ResumeThread(_sample_win32_interrupt_handle);

    return TRUE;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

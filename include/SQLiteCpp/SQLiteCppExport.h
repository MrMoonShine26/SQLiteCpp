/**
 * @file    SQLiteCppExport.h
 * @ingroup SQLiteCpp
 * @brief   File with macros needed in the generation of Windows DLLs
 *
 *
 * Copyright (c) 2012-2022 Sebastien Rombauts (sebastien.rombauts@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */

#pragma once

/*
* #define SQLITECPP_COMPILE_DLL to compile a DLL under Windows
* #define SQLITECPP_EXPORT to export symbols when creating the DLL, otherwise it defaults to importing symbols
*/

/* Windows DLL export/import */
#if defined(WIN32) && defined(SQLITECPP_COMPILE_DLL)
    #ifdef SQLITECPP_EXPORT
        #define DLL_API __declspec(dllexport)
        #pragma message("Exporting symbols")
    #else
        #define DLL_API __declspec(dllimport)
        #pragma message("Importing symbols")
    #endif        
#endif

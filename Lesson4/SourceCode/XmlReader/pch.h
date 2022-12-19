// pch.h: это предварительно скомпилированный заголовочный файл.
// Перечисленные ниже файлы компилируются только один раз, что ускоряет последующие сборки.
// Это также влияет на работу IntelliSense, включая многие функции просмотра и завершения кода.
// Однако изменение любого из приведенных здесь файлов между операциями сборки приведет к повторной компиляции всех(!) этих файлов.
// Не добавляйте сюда файлы, которые планируете часто изменять, так как в этом случае выигрыша в производительности не будет.

#ifndef PCH_H
#define PCH_H

// Добавьте сюда заголовочные файлы для предварительной компиляции
#pragma once
#include "framework.h"
#include <string>
#include <vector>
#include <cassert>
#include <array>
#include <sstream>
#include "tinyxml2.h"
#endif //PCH_H

#ifdef XMLREADER_EXPORTS
#define XMLREADER_API __declspec(dllexport)
#else
#define XMLREADER_API __declspec(dllimport)
#endif

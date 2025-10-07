#pragma once

/*
 * Hazel Engine
 * Main include file for applications using Hazel
 * 
 * Usage: #include "Hazel.h" in your application
 */

// Core functionality
#include "src/Core.h"
#include "src/Application.h"
#include "src/Log.h"
// Entry Point
// Note: This should be included LAST in the application's .cpp file
// Do NOT include this in header files!
#include "src/EntryPoint.h"  // Application includes this manually
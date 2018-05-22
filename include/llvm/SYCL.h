//===- llvm/SYCL.h - SYCL related declarations ------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares some common SYCL things.
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_SYCL_H
#define LLVM_SYCL_H

#include <string>
#include "llvm/IR/Function.h"

namespace llvm {

class Pass;
Pass *createSYCLArgsFlatteningPass(unsigned maxElements = 0);
namespace sycl {

/// Test if a function is a SYCL kernel
bool isKernel(const Function &F);

/// Register a kernel with its full name and returns its ID
///
/// If the kernel is already registered, do not register it again.
std::size_t registerSYCLKernel(const std::string &LongKernelName);

/// Construct a kernel short name for an ID
std::string constructSYCLKernelShortName(std::size_t Id);

/// Register a kernel with its full name and returns its short name
///
/// If the kernel is already registered, do not register it again.
std::string
registerSYCLKernelAndGetShortName(const std::string &LongKernelName);


}
}

#endif

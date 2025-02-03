#pragma once

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>

#include <memory>
#include <string>

class EvaLLVM {
    static constexpr auto *MODULE_ID = "EVA";
    static constexpr auto *OUTPUT_FILE = "out.ll";

public:
    EvaLLVM() { init(); }

    void exec(const std::string &program);

private:
    void init();

    void saveModuleToFile(const std::string &filename);

    std::unique_ptr<llvm::LLVMContext> context;
    std::unique_ptr<llvm::Module> module;
    std::unique_ptr<llvm::IRBuilder<>> builder;
};

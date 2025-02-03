#include "EvaLLVM.h"

#include <llvm/Support/raw_os_ostream.h>

void EvaLLVM::init() {
    context = std::make_unique<llvm::LLVMContext>();
    module = std::make_unique<llvm::Module>(MODULE_ID, *context);
    builder = std::make_unique<llvm::IRBuilder<>>(*context);
}

void EvaLLVM::exec(const std::string &program) {
    saveModuleToFile(OUTPUT_FILE);
}

void EvaLLVM::saveModuleToFile(const std::string &filename) {
    std::error_code error_code;
    llvm::raw_fd_ostream out(filename, error_code);
    assert(!error_code);

    module->print(llvm::outs(), nullptr);
    module->print(out, nullptr);
}

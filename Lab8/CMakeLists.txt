cmake_minimum_required(VERSION 3.15)
project(Lab8)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab8 app.cpp Domain/Order.cpp Domain/Order.h Domain/Food.cpp Domain/Food.h Domain/Shopping.cpp
        Domain/Shopping.h Repository/TemplateRepository.h Repository/TemplateFileRepo.h Service/Service.cpp
        Service/Service.h Domain/User.cpp Domain/User.h UI/Console.cpp UI/Console.h Tests/Tester.cpp Tests/Tester.h ValidationException.h Domain/OrderValidator.h Domain/OrderValidator.cpp)

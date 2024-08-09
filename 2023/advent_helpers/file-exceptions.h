#pragma once
//
// Created by Luke Mc on 12/1/23.
//
#include "exception"
#include "string"

namespace adventHelpers {

    class end_of_file_exception : public std::exception {
    protected:
        std::string msg;

    public:
        end_of_file_exception() : msg("Reached End of File") {};

        [[nodiscard]] const char *what() const noexcept override {
            return msg.c_str();
        }
    };

    class non_fatal_io_error : public std::exception {
    protected:
        std::string msg;

    public:
        non_fatal_io_error() : msg("Non Fatal IO Error") {};

        [[nodiscard]] const char *what() const noexcept override {
            return msg.c_str();
        }
    };

    class fatal_io_error : public std::exception {
    protected:
        std::string msg;

    public:
        fatal_io_error() : msg("Fatal IO Error") {};

        [[nodiscard]] const char *what() const noexcept override {
            return msg.c_str();
        }
    };
}
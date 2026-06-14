#include <chrono>
#include <print>
#include <thread>

#include "different_tests.hpp"

import dir_sniffer;

namespace Tests {

void DirSnifferTests() {
  {
    std::println("Simple start");

    System::DirSnifferService service("empty");

    std::println("Simple stop");
  }

  {
    std::println("Start-stop fast");

    System::DirSnifferService service("empty");
    service.Start();

    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    service.Stop();

    std::println("Start-stop fast");
  }

  {
    std::println("Start-stop long");

    System::DirSnifferService service("empty");
    service.Start();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    service.Stop();

    std::println("Start-stop long");
  }
}

}  // namespace Tests

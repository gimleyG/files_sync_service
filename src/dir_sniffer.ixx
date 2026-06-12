module;

#include <chrono>
#include <filesystem>
#include <thread>

export module dir_sniffer;

export namespace System {

class DirSnifferService {
 public:
  DirSnifferService(std::filesystem::path&& path) : m_dirPath{std::move(path)} {}
  DirSnifferService(const DirSnifferService&) = delete;
  DirSnifferService& operator=(const DirSnifferService&) = delete;

  DirSnifferService(DirSnifferService&& other) = default;
  DirSnifferService& operator=(DirSnifferService&& other) = default;

  ~DirSnifferService() { Stop(); }

  void Start() {
    if (m_workerStopper.stop_possible()) {
      return;
    }

    m_worker = std::jthread([this](std::stop_token st) { DoWork(st); });
    m_workerStopper = m_worker.get_stop_token();
  }
  void Stop() {
    if (m_workerStopper.stop_possible() && !m_workerStopper.stop_requested()) {
      m_worker.request_stop();
      m_worker.join();
    }
  }

 private:
  void DoWork(std::stop_token stopToken) {
    while (!stopToken.stop_requested()) {
      using namespace std::chrono_literals;

      std::this_thread::sleep_for(1s);
    }
  }

 private:
  std::filesystem::path m_dirPath;

  std::jthread m_worker;
  std::stop_token m_workerStopper;
};

}  // namespace System

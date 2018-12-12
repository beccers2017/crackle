#include <thread>   // for threads
#include <chrono>   // for expresssing duration
#include <atomic>   
#include <iomanip>
#include <functional>   // for std::ref()
using namespace std; 

class progress_bar {
	atomic<bool> finished; 
	atomic<int> n; 
	thread t;
public: 
	progress_bar() : finished(false),n(0), t(ref(*this)) { }    // initiate the bar by starting a new thread
	void operator() () {                                       // function executed by the thread
		while (!finished) {
			this_thread::sleep_for(chrono::milliseconds(1000));   
			cout << "\rLoading" << setw(++n) << setfill('.') << " "; 
		}
	}
	void terminate() {                                  // tell the thread/bar to stop 
		finished = true;
		if (t.joinable())
			t.join(); 
	}
};

//to use in code
progress_bar bar;
for(long i = 0; i < 3000000000L; i++) {
	bar.terminate();
}
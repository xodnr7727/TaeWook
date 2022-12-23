#include <chrono>  // std::chrono::miliseconds
#include <iostream>
#include <condition_variable> // std::condition_variable
#include <queue>
#include <mutex>
#include <cstdio>
#include <functional>
#include <string>
#include <thread>
#include <vector>
#include <future>
using namespace std;
using std::thread;
using std::vector;
using std::string;
/*
namespace ThreadPool {
class ThreadPool {
public:
	ThreadPool(size_t num_threads);
	~ThreadPool();

	//job을 추가한다.
	template <class F, class... Args>
	future<typename invoke_result<F(Args...)>::type> EnqueueJob(
		F&& f, Args&&... args);

private:
	//총 Worker 쓰레드의 개수
	size_t num_threads_;
	//Worker 쓰레드를 보관하는 벡터
	vector<thread> worker_threads_;

	//할 일들을 보관하는 job 큐
	queue<function<void()>> jobs_;
	//위의 job 큐를 위한 cv와 m
	condition_variable cv_job_q_;
	mutex m_job_q_;

	//모든 쓰레드 종료
	bool stop_all;

	//Worker 쓰레드
	void WorkerThread();

};

ThreadPool::ThreadPool(size_t num_threads)
	:num_threads_(num_threads), stop_all(false) {
	worker_threads_.reserve(num_threads);
	for(size_t i =0; i<num_threads; ++i){
		worker_threads_.emplace_back([this]() {this->WorkerThread(); });
   }
}
void ThreadPool::WorkerThread() {
	while (true) {
		unique_lock<mutex> lock(m_job_q_);
		cv_job_q_.wait(lock, [this]() {return !this->jobs_.empty() || stop_all; });
		if (stop_all && this->jobs_.empty()) {
			return;
		}

		//맨앞의 job 을 뺀다.
		function<void()> job = move(jobs_.front());
		jobs_.pop();
		lock.unlock();

		//해당 job 을 수행한다.
		job();
	}
}
ThreadPool::~ThreadPool() {
	stop_all = true;
	cv_job_q_.notify_all();

	for (auto& t : worker_threads_) {
		t.join();
	}
}

template <class F, class... Args>
std::future<typename std::invoke_result<F(Args...)>::type> ThreadPool::EnqueueJob
(F&& f, Args&&... args) {
	if (stop_all) {
		throw std::runtime_error("ThreadPool 사용 중지됨");
	}

	using return_type = typename std::invoke_result<F(Args...)>::type;
	auto job = make_shared<packaged_task<return_type()>>(
		bind(forward<F>(f), forward<Args>(args)...));
	future<return_type> job_result_future = job->get_future();
	{
		lock_guard<mutex> lock(m_job_q_);
		jobs_.push([job]() { (*job)(); });
	}
		cv_job_q_.notify_one();

		return job_result_future;
	}

}

int work(int t, int id) {
	printf("%d start \n", id);
	this_thread::sleep_for(chrono::seconds(t));
	printf("%d end after %ds\n", id, t);
	return t + id;
}

int main() {
	ThreadPool::ThreadPool pool(3);
	

	vector<future<int>> futures;
	for (int i = 0; i < 10; i++) {
		futures.emplace_back(pool.EnqueueJob(work, i % 3 + 1, i));
	}
	for (auto& f : futures) {
		printf("result : %d \n", f.get());
	}
}*/
/*
int do_work(int x) {
	// x를 가지고 무슨 일을 한다
	this_thread::sleep_for(chrono::seconds(3));
	return x;
}
void do_work_parallel() {
	auto f1 = async([]() {do_work(3); });
	auto f2 = async([]() {do_work(3); });
	do_work(3);

	f1.get();
	f2.get();
}

void do_work_sequential() {
	do_work(3);
	do_work(3);	
	do_work(3);
}
int main() { do_work_parallel(); }
*/
/*
//std::accumulate 와 동일
int sum(const vector<int>& v, int start, int end) {
	int total = 0;
	for (int i = start; i < end; ++i) {
		total += v[i];
	}
	return total;
}

int parallel_sum(const vector<int>& v) {
	//lower_half_future 는 1~500 까지 비동기적으로 더함
	//참고로 람다 함수를 사용하면 좀 더 깔끔하게 표현할 수 도 있다
	//--> std::aysnc([&v]() {return sum(v,0,v.size() / 2); });
	future<int> lower_half_future =
		async(launch::async, sum, cref(v), 0, v.size() / 2);

	//upper_half 는 501 부터 1000까지 더함
	int upper_half = sum(v, v.size() / 2, v.size());

	return lower_half_future.get() + upper_half;
}
int main() {
	vector<int> v;
	v.reserve(1000);

	for (int i = 0; i < 1000; i++) {
		v.push_back(i + 1);
	}
	cout << "1부터 1000까지의 합 : " << parallel_sum(v)
}*/

/*
int some_task(int x) { return 10 + x; }

int main() {
	//int(int) : int 를 리턴하고 인자로 int 를 받는 함수. (std::function 참조)
	packaged_task<int(int)> task(some_task);

	future<int> start = task.get_future();

	//packaged_task 는 복사 생성이 불가능하므로(promise 도 마찬가지) 명시적으로 move를 해줘야한다.
	thread t(move(task), 5);

	cout << "결과값 : " << start.get() << endl;
	t.join();
}*/

/*
void runner(shared_future<void>* start) {
	start->get();
	cout << "출발!" << endl;
}
int main() {
	promise<void> p;
	shared_future<void> start = p.get_future();

	thread t1(runner, &start);
	thread t2(runner, &start);
	thread t3(runner, &start);
	thread t4(runner, &start);

	//참고로 cerr 는 std::cout 과는 다르게 버퍼를 사용하지 않기 때문에 터미널에 바로 출려된다
	cerr << "준비...";
	this_thread::sleep_for(chrono::seconds(1));
	cerr << "땅!" << endl;

	p.set_value();

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}*/

/*
void worker(promise<void>* p) {
	this_thread::sleep_for(chrono::seconds(10));
	p->set_value();
}
int main() {
	//void 의 경우 어떠한 객체도 전달하지 않지만, future 가 set이 되었냐
	//안되었느냐의 유무로 마치 플래그의 역할을 수행할수있다.
	promise<void> p;

	//미래에 promise 데이터를 돌려 주겠다는 약속.
	future<void> data = p.get_future();

	thread t(worker, &p);

	//미래에 약속된 데이터를 받을때까지 기다린다.
	while (true) {
		future_status status = data.wait_for(chrono::seconds(10));

		//아직 준비가 안됨
		if (status == future_status::timeout) {
			cerr << ">";
		}
		//promise 가 future 를 설정함
		else if (status == future_status::ready) {
			break;
		}
	}
	t.join();
}*/

/*
condition_variable cv;
mutex m;
bool done = false;
string info;

void worker() {
	{
		lock_guard<mutex> lk(m);
		info = "some data"; // 아래의 p->set_value("some data") 에 대응
		done = true;
	}
	cv.notify_all();
}
int main() {
	thread t(worker);

	unique_lock<mutex> lk(m);
	cv.wait(lk, [] {return done; }); // 아래의 data.wait() 이라 보면 된다.
	lk.unlock();

	cout << "받은 데이터 : " << info << endl;

	t.join();
}*/

/*
void worker(promise<string>* p) {
	try{
		throw runtime_error("Some Error!");
	}
	catch (...) {
		//set_exception 에는 excepting_ptr 를 전달해야 한다.
		p->set_exception(current_exception());
	}
	//약속을 이행하는 모습, 해당 결과는 future 에 들어간다
	//p->set_value("some data");
}
int main() {
	promise<string> p;

	//미래에 promise 데이터를 돌려 주겠다는 약속.
	future<string> data = p.get_future();

	thread t(worker, &p);

	//미래에 약속된 데이터를 받을때 까지 기다린다.
	data.wait();

	try {
		data.get();
	}catch(const exception &e){
		cout << "예외 : " << e.what() << endl;
	}

	//wait이 리턴했다는 뜻이 future 에 데이터가 준비되었다는 의미.
	//참고로 wait 없이 그냥 get 해도 wait 한 것과 같다.
	//cout << "받은 데이터 : " << data.get() << endl;

	t.join();
}*/

/*
void producer(queue<string>* downloaded_pages, mutex* m,
	int index, condition_variable* cv) {
	for (int i = 0; i < 5; i++) {
		//웹사이트를 다운로드 하는데 걸리는 시간이라고 생각하면 된다
		//각 쓰레드 별로 다운로드 하는데 걸리는 시간이 다르다.
		this_thread::sleep_for(chrono::milliseconds(100 * index));
		string content = "웹사이트 : " + to_string(i) + " from thread(" +
			to_string(index) + ")\n";

		//data는 쓰레드 사이에서 공유되므로 critical section 에 넣어야 한다.
		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		//consumer 에게 content 가 준비되었음을 알린다.
		cv->notify_one();
	}
}
void consumer(queue<string>* downloaded_pages, mutex* m,
	int* num_processed, condition_variable* cv) {
	//전체 처리하는 페이지 개수 5 * 5 = 25개
	while (*num_processed < 25) {
		unique_lock<mutex> lk(*m);

		cv->wait(
			lk, [&] {return !downloaded_pages->empty() || *num_processed == 25; });
		if (*num_processed == 25) {
			lk.unlock();
			return;
		}

		//맨 앞의 페이지를 읽고 대기 목록에서 제거한다.
		string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();

		//content 를 처리한다
		cout << content;
		this_thread::sleep_for(chrono::microseconds(80));
	}
}
int main() {
	//현재 다운로드한 페이지를 리스트로, 아직 처리되지 않은 것들이다.
	queue<string> downloaded_pages;
	mutex m;
	condition_variable cv;

	vector<thread> producers;
	for (int i = 0; i < 5; i++) {
		producers.push_back(
			thread(producer, &downloaded_pages, &m, i + 1, &cv));
	}

	int num_processed = 0;
	vector<thread> consumers;
	for (int i = 0; i < 3; i++) {
		consumers.push_back(
			thread(consumer, &downloaded_pages, &m, &num_processed, &cv));
	}
	for (int i = 0; i < 5; i++) {
		producers[i].join();
	}
	//나머지 자고 있는 쓰레드들을 모두 깨운다.
	cv.notify_all();

	for (int i = 0; i < 5; i++) {
		consumers[i].join();
	}
}*/


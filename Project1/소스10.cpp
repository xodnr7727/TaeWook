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

	//job�� �߰��Ѵ�.
	template <class F, class... Args>
	future<typename invoke_result<F(Args...)>::type> EnqueueJob(
		F&& f, Args&&... args);

private:
	//�� Worker �������� ����
	size_t num_threads_;
	//Worker �����带 �����ϴ� ����
	vector<thread> worker_threads_;

	//�� �ϵ��� �����ϴ� job ť
	queue<function<void()>> jobs_;
	//���� job ť�� ���� cv�� m
	condition_variable cv_job_q_;
	mutex m_job_q_;

	//��� ������ ����
	bool stop_all;

	//Worker ������
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

		//�Ǿ��� job �� ����.
		function<void()> job = move(jobs_.front());
		jobs_.pop();
		lock.unlock();

		//�ش� job �� �����Ѵ�.
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
		throw std::runtime_error("ThreadPool ��� ������");
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
	// x�� ������ ���� ���� �Ѵ�
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
//std::accumulate �� ����
int sum(const vector<int>& v, int start, int end) {
	int total = 0;
	for (int i = start; i < end; ++i) {
		total += v[i];
	}
	return total;
}

int parallel_sum(const vector<int>& v) {
	//lower_half_future �� 1~500 ���� �񵿱������� ����
	//����� ���� �Լ��� ����ϸ� �� �� ����ϰ� ǥ���� �� �� �ִ�
	//--> std::aysnc([&v]() {return sum(v,0,v.size() / 2); });
	future<int> lower_half_future =
		async(launch::async, sum, cref(v), 0, v.size() / 2);

	//upper_half �� 501 ���� 1000���� ����
	int upper_half = sum(v, v.size() / 2, v.size());

	return lower_half_future.get() + upper_half;
}
int main() {
	vector<int> v;
	v.reserve(1000);

	for (int i = 0; i < 1000; i++) {
		v.push_back(i + 1);
	}
	cout << "1���� 1000������ �� : " << parallel_sum(v)
}*/

/*
int some_task(int x) { return 10 + x; }

int main() {
	//int(int) : int �� �����ϰ� ���ڷ� int �� �޴� �Լ�. (std::function ����)
	packaged_task<int(int)> task(some_task);

	future<int> start = task.get_future();

	//packaged_task �� ���� ������ �Ұ����ϹǷ�(promise �� ��������) ��������� move�� ������Ѵ�.
	thread t(move(task), 5);

	cout << "����� : " << start.get() << endl;
	t.join();
}*/

/*
void runner(shared_future<void>* start) {
	start->get();
	cout << "���!" << endl;
}
int main() {
	promise<void> p;
	shared_future<void> start = p.get_future();

	thread t1(runner, &start);
	thread t2(runner, &start);
	thread t3(runner, &start);
	thread t4(runner, &start);

	//����� cerr �� std::cout ���� �ٸ��� ���۸� ������� �ʱ� ������ �͹̳ο� �ٷ� ����ȴ�
	cerr << "�غ�...";
	this_thread::sleep_for(chrono::seconds(1));
	cerr << "��!" << endl;

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
	//void �� ��� ��� ��ü�� �������� ������, future �� set�� �Ǿ���
	//�ȵǾ������� ������ ��ġ �÷����� ������ �����Ҽ��ִ�.
	promise<void> p;

	//�̷��� promise �����͸� ���� �ְڴٴ� ���.
	future<void> data = p.get_future();

	thread t(worker, &p);

	//�̷��� ��ӵ� �����͸� ���������� ��ٸ���.
	while (true) {
		future_status status = data.wait_for(chrono::seconds(10));

		//���� �غ� �ȵ�
		if (status == future_status::timeout) {
			cerr << ">";
		}
		//promise �� future �� ������
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
		info = "some data"; // �Ʒ��� p->set_value("some data") �� ����
		done = true;
	}
	cv.notify_all();
}
int main() {
	thread t(worker);

	unique_lock<mutex> lk(m);
	cv.wait(lk, [] {return done; }); // �Ʒ��� data.wait() �̶� ���� �ȴ�.
	lk.unlock();

	cout << "���� ������ : " << info << endl;

	t.join();
}*/

/*
void worker(promise<string>* p) {
	try{
		throw runtime_error("Some Error!");
	}
	catch (...) {
		//set_exception ���� excepting_ptr �� �����ؾ� �Ѵ�.
		p->set_exception(current_exception());
	}
	//����� �����ϴ� ���, �ش� ����� future �� ����
	//p->set_value("some data");
}
int main() {
	promise<string> p;

	//�̷��� promise �����͸� ���� �ְڴٴ� ���.
	future<string> data = p.get_future();

	thread t(worker, &p);

	//�̷��� ��ӵ� �����͸� ������ ���� ��ٸ���.
	data.wait();

	try {
		data.get();
	}catch(const exception &e){
		cout << "���� : " << e.what() << endl;
	}

	//wait�� �����ߴٴ� ���� future �� �����Ͱ� �غ�Ǿ��ٴ� �ǹ�.
	//����� wait ���� �׳� get �ص� wait �� �Ͱ� ����.
	//cout << "���� ������ : " << data.get() << endl;

	t.join();
}*/

/*
void producer(queue<string>* downloaded_pages, mutex* m,
	int index, condition_variable* cv) {
	for (int i = 0; i < 5; i++) {
		//������Ʈ�� �ٿ�ε� �ϴµ� �ɸ��� �ð��̶�� �����ϸ� �ȴ�
		//�� ������ ���� �ٿ�ε� �ϴµ� �ɸ��� �ð��� �ٸ���.
		this_thread::sleep_for(chrono::milliseconds(100 * index));
		string content = "������Ʈ : " + to_string(i) + " from thread(" +
			to_string(index) + ")\n";

		//data�� ������ ���̿��� �����ǹǷ� critical section �� �־�� �Ѵ�.
		m->lock();
		downloaded_pages->push(content);
		m->unlock();

		//consumer ���� content �� �غ�Ǿ����� �˸���.
		cv->notify_one();
	}
}
void consumer(queue<string>* downloaded_pages, mutex* m,
	int* num_processed, condition_variable* cv) {
	//��ü ó���ϴ� ������ ���� 5 * 5 = 25��
	while (*num_processed < 25) {
		unique_lock<mutex> lk(*m);

		cv->wait(
			lk, [&] {return !downloaded_pages->empty() || *num_processed == 25; });
		if (*num_processed == 25) {
			lk.unlock();
			return;
		}

		//�� ���� �������� �а� ��� ��Ͽ��� �����Ѵ�.
		string content = downloaded_pages->front();
		downloaded_pages->pop();

		(*num_processed)++;
		lk.unlock();

		//content �� ó���Ѵ�
		cout << content;
		this_thread::sleep_for(chrono::microseconds(80));
	}
}
int main() {
	//���� �ٿ�ε��� �������� ����Ʈ��, ���� ó������ ���� �͵��̴�.
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
	//������ �ڰ� �ִ� ��������� ��� �����.
	cv.notify_all();

	for (int i = 0; i < 5; i++) {
		consumers[i].join();
	}
}*/


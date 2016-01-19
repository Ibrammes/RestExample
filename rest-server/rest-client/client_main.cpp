#include <cpprest\http_client.h>
#include <codecvt>  //��� ����������� (��������� ���������)

using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace std;
//using namespace concurrency::streams;  //��� ���������� ������

int main()
{
	http_client client(L"http://localhost:8080");
	pplx::task<http::http_response> resp = client.request(methods::GET, L"/restdemo");
	resp.then([=](http_response response)
	{
		
		concurrency::streams::istream bodyStream = response.body();  //��������� ���� ������ � ���� ������
		concurrency::streams::container_buffer<string> inStringBuffer;  //����� ��� ���������� ������ ���� ������
		bodyStream.read_to_end(inStringBuffer);
		string &text = inStringBuffer.collection();
		wstring_convert<codecvt_utf8_utf16<wchar_t>, wchar_t> utf16conv;
		wostringstream ss;
		ss << utf16conv.from_bytes(text.c_str()) << std::endl;
		//ss << response.headers().content_length() << endl;  //����� ������
		wcout << ss.str();
	});
	//resp.wait();

	getchar();
	return 0;
}
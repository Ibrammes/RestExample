#include "MyListener.h"

MyListener::MyListener(const http::uri& url) : m_listener(http_listener(url))
{
	m_listener.support(methods::GET, std::tr1::bind(&MyListener::handle_get, this, std::tr1::placeholders::_1)); 
	//m_listener.support(methods::PUT, std::tr1::bind(&MyListener::handle_put, this, std::tr1::placeholders::_1));
	//	m_listener.support(methods::POST, std::tr1::bind(&MyListener::handle_post, this, std::tr1::placeholders::_1));
	//	m_listener.support(methods::DEL, std::tr1::bind(&MyListener::handle_delete, this, std::tr1::placeholders::_1));
}

void MyListener::handle_get(http_request message)
{
	message.reply(status_codes::OK, U("Hello, World!"));
}

void MyListener::start()
{
	m_listener.open().then([this]()
	{
		//cout << "Server start" << endl;
		//	m_listener.close();
	}).wait();
}
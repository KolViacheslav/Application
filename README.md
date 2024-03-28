## Програмний засіб розпізнавання нових підключень до комп'ютерної мережі

Application - це простий додаток, який дозволяє сканувати вибрану локальну мережу(жі) серверу на наявність сторонніх пристроїв, що підключаються/підключені в неї. 

**# Зміст**
* [Вступ](#вступ)
* [Вимоги](#вимоги)
* [Встановлення](#встановлення)
* [Використання](#використання)

**# Вступ**

Application - це чудовий інструмент для адміністратора мержі. Він дозволяє контролювати стан локальної мережі, перелік підклюних (дозволених/не дозволених) пристроїв, який зберігається в DataBase SQLite.

**# Вимоги**

Linux Server (рекомендовано Debian 12.2.0-14)

GCC 12.2.0 та вище

libsqlite3-dev

**# Встановлення**

Встановіть допоміжні пакети для правильної збірки проекту.

sudo apt install git

sudo apt install cmake

sudo apt install libsqlite3-dev

Склонуйте репозиторій:

git clone ["url"](https://github.com/KolViacheslav/Application.git)

Ініціалізуйте та завантажте допоміжні бібліотеки.

git submodule init

git submodule update

Перейдіть в директорію проекту.

cd Application

Якщо не створилась директорія "build", то створіть її і перейдіть до неї.

mkdir build

cd build

Якщо все правильно, то можете зібрати проект командою:

cmake ..

**# Використання**

Цей проект робився під конкретний web - NginX. Отже, приклад використання:

Встановлюємо пакет з nginx.

sudo apt install nginx

Обов'язково від імені Адміністратора змінюємо конфігурацію вашого сайта.

sudo nano /etc/nginx/sites-available/{default}

{default} - ваш файл з конфігурацією

Добавляємо до вашої конфігурації:

location /index {
		fastcgi_pass 127.0.0.1:8000;

		fastcgi_param	GATEWAY_INTERFACE	CGI/1.1;
                fastcgi_param	SERVER_SOFTWARE		nginx;
                fastcgi_param	QUERY_STRING		$query_string;
                fastcgi_param	REQUEST_METHOD		$request_method;
                fastcgi_param	CONTENT_TYPE		$content_type;
                fastcgi_param	CONTENT_LENGTH		$content_length;
                fastcgi_param	SCRIPT_FILENAME		$document_root$fastcgi_script_name;
                fastcgi_param	SCRIPT_NAME		$fastcgi_script_name;
                fastcgi_param	REQUEST_URI		$request_uri;
                fastcgi_param	DOCUMENT_URI		$document_uri;
                fastcgi_param	DOCUMENT_ROOT		$document_root;
                fastcgi_param	SERVER_PROTOCOL		$server_protocol;
                fastcgi_param	REMOTE_ADDR		$remote_addr;
                fastcgi_param	REMOTE_PORT		$remote_port;
                fastcgi_param	SERVER_ADDR		$server_addr;
                fastcgi_param	SERVER_PORT		$server_port;
		fastcgi_param	SERVER_NAME		$server_name;
  }

Зберігаємо файл конфігурації сайта.

Повертаємось до нашого проекту. Переходимо в директорію bin та запускаємо наш процес.

сd bin

sudo spawn-fcgi -p {port} Application

{port} - будь-який відкритий порт який ви вказали під час конфігурації файла сайту.

Все готово. Перейдіть за посиланням http://localhost:80

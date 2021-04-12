FROM	debian:buster

RUN		apt-get update && apt-get upgrade && apt-get -y install \
		nginx \
		openssl \
		vim \
		mariadb-server \
		php-mysql \
		wget \
		php-fpm

RUN		openssl req -newkey rsa:4096 -days 365 -nodes -x509 -subj "/C=KR/ST=Seoul/L=Seoul/O=42Seoul/OU=GAM/CN=localhost" -keyout localhost.dev.key -out localhost.dev.crt
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		tar	-xvf phpMyAdmin-5.0.2-all-languages.tar.gz
RUN		wget https://wordpress.org/latest.tar.gz
RUN		tar -xvf latest.tar.gz

COPY	./srcs/default etc/nginx/sites-available/
COPY	./srcs/config.inc.php phpMyAdmin-5.0.2-all-languages
COPY	./srcs/wp-config.php wordpress
COPY	./srcs/run.sh .

EXPOSE	80 443

CMD		sh run.sh

#!/bin/bash

chmod	600 localhost.dev.crt localhost.dev.key
mv		localhost.dev.crt /etc/ssl/certs/
mv		localhost.dev.key /etc/ssl/private/
mv		phpMyAdmin-5.0.2-all-languages phpmyadmin
mv		phpmyadmin /var/www/html/
service mysql start
service php7.3-fpm start
echo "CREATE DATABASE IF NOT EXISTS wordpress" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON *.* TO 'user'@'%' IDENTIFIED BY '1111' WITH GRANT OPTION" | mysql -u root --skip-password
echo "FLUSH PRIVILEGES" | mysql -u root --skip-password

service	mysql reload
service php7.3-fpm restart

mv		wordpress /var/www/html/
if [ $AUTOINDEX -eq 0 ]; then
        cp /etc/nginx/sites-available/default_non_autoindex /etc/nginx/sites-available/default
fi
chown -R www-data:www-data /var/www/html/wordpress

service nginx start
bash

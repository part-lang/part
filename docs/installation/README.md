### Requirement
```
Zend Engine 2 or 3
GCC
Zephir lang
PHP-Dev
libpcre3-dev
```

## First Installation

### Quick Installation
this installation only work for Ubuntu and debian,etc
```bash
git clone https://github.com/part-lang/part.git
cd part
./install
```

### Manual Installation
```
Coming soon
```



## Integration Installation

### Intergrated with Nginx

Install nginx web server on your machine

Running Part server on port 8080

```bash
cd /var/www/
part run 8080
```

Edit /etc/nginx/sites-available/default
```nginx
server {
    listen 80;

    server_name example.com;

    location / {
        proxy_pass http://0.0.0.0:8080;
        proxy_http_version 1.1;
        proxy_set_header Upgrade $http_upgrade;
        proxy_set_header Connection 'upgrade';
        proxy_set_header Host $host;
        proxy_cache_bypass $http_upgrade;
    }
}
```

Reload and restart nginx
```bash
sudo service nginx reload
sudo service nginx restart
```

from python:2.7-slim
workdir /app
copy . /app
run pip install --trusted-host pypi.python.org -r requirements.txt
expose 80
env NAME World
cmd ["python", "app.py"]

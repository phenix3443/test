from django.shortcuts import render, render_to_response

# Create your views here.


def index(request):
    person = {
        "name": "guest",
        "message": "welcome",
    }

    if request.method == "POST":
        person["name"] = request.POST["name"]

    print(person["name"])
    context = {"person": person}
    return render(request, 'hello.html', context)

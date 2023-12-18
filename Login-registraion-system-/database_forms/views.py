from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from django.urls import reverse
def index(request):
    return render(request, 'index.html')

def register(request):
    # return HttpResponse("la register vayo hai")
    return render (request, 'register.html')

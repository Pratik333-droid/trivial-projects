from django.http import HttpResponse
from django.shortcuts import render
from django.http import HttpResponse, HttpResponseRedirect
from django.urls import reverse
from .models import Users
from .verify_password import isValid
# Create your views here.
def index(request):
    return HttpResponse ("Welcome to UserRegistration")

def holy(request):
    return HttpResponse ("holy")
    
def registerData(request):
    # return HttpResponse ("la badiya")
    username = request.POST["username"]
    password1 = request.POST["password"]
    password2 = request.POST["confirm_password"]
    dct = {'password_match':""}
    if password1 == password2:
        if isValid(password1) == True:
            user = Users(username = username, password = password1)
            user.save()
        else:
            dct['password_match'] = "The entered password doesn't meet the required criteria."

        # return HttpResponseRedirect(reverse('register'))
    else:
        dct['password_match'] = "The entered passwords do not match."
    
    # return HttpResponseRedirect(reverse('register'))
    return render (request, 'register.html', dct)
    #  the reverse function allows to retrieve url details from url’s.py file through the name value provided there

    # return render (request, 'register.html')
    # return HttpResponse("la badiya")

def displayRegisteredUsers(request):
    registeredUsers = Users.objects.all().values()
    registeredUsersDictionary = {'registeredUsers' : registeredUsers}
    return render (request, 'registeredUsers.html', registeredUsersDictionary)

def delete(request, id):
    x = Users.objects.get(id = id)
    x.delete()
    # displayRegisteredUsers(request)
    return HttpResponseRedirect(reverse('displayRegisteredUsers'))

def loginPage(request):
    return render(request, "login.html")

def login(request):
    username = request.POST["login_username"]
    password = request.POST["login_password"]
    
    registeredUsers = Users.objects.all().values()
    for i in registeredUsers:
        if i["username"] == username and i["password"] == password:
            return HttpResponse("Kangratulations Login Successfull. Badiya badiya")

    return HttpResponse("Either Username or id is incorrect.")

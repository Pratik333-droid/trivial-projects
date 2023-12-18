from xml.etree.ElementInclude import include
from django.contrib import admin
from django.urls import path
from . import views

urlpatterns = [

    path('', views.index, name= "index"),
    path('/registerData', views.registerData, name= "registerData"),
    path('/holy', views.holy, name= "holy"),
    path('/login', views.login, name= "login"),
    path('/loginPage', views.loginPage, name= "loginPage"),
    path('/displayRegisteredUsers', views.displayRegisteredUsers, name= "displayRegisteredUsers"),
    path('/delete/<int:id>', views.delete, name= "delete")
]
from django.shortcuts import render
from .forms import LoginForm, UserRegistrationForm
from django.contrib.auth import authenticate, login
from django.http import HttpResponse
from django.shortcuts import render
from django.contrib.auth.decorators import login_required
# Create your views here.
def user_login(request):
    if request.method == 'POST':
        form = LoginForm(request.POST) #############
        if form.is_valid(): #############
            cd = form.cleaned_data
            print("form.cleaned_data = ", cd)
            user = authenticate(request, username = cd['username'], password = cd['password'])
            #the above authenticate function returns user object if the 
            #user is authenticated successfully else it returns None
            if user is not None:
                print(f"user = {user}")
                print(f"user.first_name = {user.first_name}")
                print(f"request.user = {request.user} ")
                #is_active is an attribute of django model. It is a boolena
                #field which is usually true by default. If it's set to
                #flase, user can't login.
                if user.is_active:
                    login(request, user)
                    print(f"request.user = {request.user} ")
                    print(f"user.first_name = {request.user.first_name}")
                    return HttpResponse ('Authenticated Successfully')
 
                else:
                    return HttpResponse('Disabled account')
            
            else:
                return HttpResponse('Invalid Login')
         
    else:
        form = LoginForm()
    return render(request, 'account/login.html', {'form': form})

@login_required
def dashboard (request):
    return render(request, 'account/dashboard.html', {'section': 'dashboard'})

def register(request):
    if request.method == 'POST':
        user_form = UserRegistrationForm(request.POST)
        print(f"user_form = {user_form}")
        if user_form.is_valid():
        # Create a new user object but avoid saving it yet
            new_user = user_form.save(commit=False)
            # Set the chosen password. the set password 
            # function takes care of hashing things
            new_user.set_password(
            user_form.cleaned_data['password'])
            # Save the User object
            new_user.save()
            return render(request,
            'account/register_done.html',
            {'new_user': new_user})

    else:
        user_form = UserRegistrationForm()
    #keeping return out of else block ensures that
    #register.html template is rendered evenif
    #user_form is invalid.
    return render(request,
    'account/register.html',
    {'user_form': user_form})

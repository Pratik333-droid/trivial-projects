from django.urls import path, include
from . import views
from django.contrib.auth import views as auth_views
urlpatterns = [
 # post views
#  path('login/', views.user_login, name='login'),
path('', include('django.contrib.auth.urls')),
path('login/', auth_views.LoginView.as_view(), name='login'),
path('logout/', auth_views.LogoutView.as_view(), name='logout'),
path('', views.dashboard, name = 'dashboard'),
path('password_change/',
 auth_views.PasswordChangeView.as_view(),
 name='password_change'),
path('password_change/done/',
 auth_views.PasswordChangeDoneView.as_view(),
 name='password_change_done'),
# in urls.py, one needs to use as_view() method to differentiate a class based view from function based view.
path('password_reset/',
 auth_views.PasswordResetView.as_view(),
 name='password_reset'),
path('password_reset/done/',
 auth_views.PasswordResetDoneView.as_view(),
 name='password_reset_done'),
path('reset/<uidb64>/<token>/',
 auth_views.PasswordResetConfirmView.as_view(),
 name='password_reset_confirm'),
path('reset/done/',
 auth_views.PasswordResetCompleteView.as_view(),
 name='password_reset_complete'),
path('register/', views.register, name='register'),
] 

#  the PasswordChangeView class is decorated with the login_required decorator, which requires the user to be authenticated in order to access the view.
#  The login_required decorator will redirect the user to the login page if they are not authenticated, and will pass the original URL as the next parameter. This allows the login view to redirect the user back to the 'password_change/' URL after they have logged in.

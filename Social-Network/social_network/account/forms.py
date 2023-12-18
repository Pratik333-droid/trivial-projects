from django import forms
from django.contrib.auth.models import User
# LoginForm class inherits from Form class present in form module
class LoginForm(forms.Form):
    username = forms.CharField(max_length = 20, min_length=2)
    password = forms.CharField(widget= forms.PasswordInput)
    # A widget is Django’s representation of an HTML input element type.

class UserRegistrationForm(forms.ModelForm):
    password = forms.CharField(label='Password',
    widget=forms.PasswordInput)
    password2 = forms.CharField(label='Repeat password',
    widget=forms.PasswordInput)
    class Meta:
        model = User
        fields = ('username', 'first_name', 'email')

    #check second password against the first one.
    def clean_password2(self):
        cd = self.cleaned_data
        if cd['password'] != cd['password2']:
            raise forms.ValidationError('Passwords don\'t match.')
        return cd['password2']
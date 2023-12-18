from django.apps import AppConfig

# this class is included in the django settings.py installed_apps = []
# makemigration command stores changes to the migration file and migrate command loads the changes to the database
class AccountConfig(AppConfig):
    default_auto_field = 'django.db.models.BigAutoField'
    name = 'account'

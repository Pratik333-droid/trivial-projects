def containsLower(password):
    for i in password:
        if i.islower() == True:
            return True
    return False
    
def containsUpper(password):
    for i in password:
        if i.isupper() == True:
            return True
    return False
    
def containsSpecialCharacter(password):
    symbols = "!@$%^&*+/#-_,.`~?"
    for i in password:
        if i in symbols:
            return True
    return False

def isLongEnough(password):
    return True if len(password) > 7 else False

def isValid(password):
    validity = containsLower(password) and containsUpper(password) and containsSpecialCharacter(password) and isLongEnough(password)
    return validity
"""
This is the file with your answer, do not rename or move it.
Write your code in it, and save it before submitting your answer.
"""

def is_valid_socket_address(socket_address):
    """Determine if the provided string is a valid socket address.
    This function declaration must be kept unmodified.

    Args:
        socket_address: A string with a socket address, eg, 
            '127.12.23.43:5000', to be checked for validity.
    Returns:
        A boolean indicating whether the provided string is a valid 
        socket address.
    """
    # write your implementation here

    # Boolean to send at the end
    valid_address = False

    # First try to check if the address has the correct format
    try:
        # Create a list, splitting the address by the "."
        ints = socket_address.split(".")
        # First, if the list is well created, it will have a length of 4
        if len(ints) == 4:
            # If it has the correct length, we assign the variables
            x = int(ints[0])
            y = int(ints[1])
            z = int(ints[2])
            aux = ints[3]
            # Now we have to get the port
            ports = aux.split(":")
            # Check if the port can be divided by 2
            if len(ports) == 2:
                w = int(ports[0])
                p = int(ports[1])
                # Condition if the values of x y z w and p are in the correct ranges
                if (0 < x and x < 255) and \
                        (0 < y and y < 255) and \
                        (0 < z and z < 255) and \
                        (0 < w and w < 255) and \
                        (1 < p and p < 65535):
                    # If it passes al yhe conditions, it means that it a valid address
                    valid_address = True
    except:
        #If an error appears, the address is not valid
        valid_address = False

    return valid_address


# This tests your code with the examples given in the question, 
# and is provided only for your convenience.
if __name__ == '__main__':
    for socket_address in ["127.12.23.43:5000",
                   "127.A:-12"]:
        print is_valid_socket_address(socket_address)



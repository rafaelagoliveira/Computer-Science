"""
Deterministic Finite Automaton (DFA) - Word Verifier

The code implements an interactive program that allows the creation and
verification of words with respect to a Deterministic Finite Automaton (DFA).

Format: Flake8
"""


def read_alphabet():
    """
    Prompts the user to enter the alphabet separated by commas and returns a list of alphabet symbols.
    """

    alphabet = input('\nEnter the alphabet: ')
    return alphabet.split(',')


def read_states():
    """
    Prompts the user to enter the states separated by commas and returns a list of states.
    """

    states = input('Enter the states: ')
    return states.split(',')


def read_initial_state(states):
    """
    Prompts the user to enter the initial state and checks if it is present in the list of states.
    Returns the initial state.
    """

    while True:
        state = input('Enter the initial state: ')
        if state in states:
            return state
        print('Enter a valid state.')


def read_accepting_states(states):
    """
    Prompts the user to enter the accepting states separated by commas and checks if all the provided states
    are present in the list of states.
    Returns a list of accepting states.
    """

    while True:
        states_input = input('Enter the accepting states: ')
        states_input = states_input.split(',')
        if all(state in states for state in states_input):
            return states_input
        print('Enter valid states.')


def read_transition_table(states, alphabet):
    """
    Prompts the user to enter the transitions for each state and alphabet symbol of the automaton.
    Checks if the transitions are valid states or '-' to represent the absence of a transition.
    Returns a transition table represented by a dictionary.
    """

    table = {}

    for state in states:
        table[state] = {}
        for symbol in alphabet:
            while True:
                transition = input(f'Delta({state},{symbol}): ')
                if transition == '-' or transition in states:
                    table[state][symbol] = transition
                    break

    return table


def verify_valid_word(word, alphabet):
    """
    Verifies if all symbols in the word are present in the provided alphabet.
    Returns True if the word is valid, and False otherwise.
    """

    for symbol in word:
        if symbol not in alphabet:
            return False

    return True


def verify_acceptance(word, transition_table, accepting_states, initial_state):
    """
    Verifies if the word is accepted by the deterministic automaton.
    Uses the transition table, accepting states, and initial state to simulate the word processing.
    Returns True if the word is accepted, False if it is rejected, and None if processing is not possible.
    """

    current_state = initial_state

    for symbol in word:
        if current_state not in transition_table or symbol not in transition_table[current_state]:
            return False
        current_state = transition_table[current_state][symbol]
        if current_state == '-':
            return None

    return current_state in accepting_states


def print_transition_table(alphabet, states, transition_table):
    """
    Prints the transition table formatted with alphabet symbols and states.
    """

    print('   ', end='')
    for symbol in alphabet:
        print(symbol, end='  ')
    print()

    for state in states:
        print(f'{state}|', end='')
        for symbol in alphabet:
            if symbol in transition_table[state]:
                print(f' {transition_table[state][symbol]} ', end='')
        print()


def run_verification(alphabet, transition_table, accepting_states, initial_state):
    """
    Executes the word verification loop.
    Prompts the user to enter a word to be verified by the automaton.
    Performs the verification and displays the result.
    Allows the user to choose whether to enter a new word, a new automaton, or exit the program.
    Returns the chosen option.
    """

    repeat = 1

    while repeat == 1:
        word = input('\nEnter the word to be verified: ')
        if not verify_valid_word(word, alphabet):
            print('Word contains invalid symbols.')
        else:
            verifier = verify_acceptance(word, transition_table, accepting_states, initial_state)
            if verifier:
                print('\nSuccess!')
            elif verifier is None:
                print('\nThe DFA is unable to process the provided word.')
            elif verifier is False:
                print('\nWord not recognized!')

        while True:
            try:
                repeat = int(input('\n1 - New word\n2 - New automaton\n3 - Exit\n--> '))
                if repeat < 1 or repeat > 3:
                    raise ValueError
                break
            except ValueError:
                print('Invalid input. Please enter a valid value.')

    return repeat


def main():
    """
    Main function that controls the program flow.
    Performs the reading of the alphabet, states, initial state,
    accepting states, and transition table.
    Prints the transition table and executes the word verification.
    Repeats the process until the user chooses to exit the program.
    """

    repeat = 0

    while repeat <= 2:
        alphabet = read_alphabet()
        states = read_states()
        initial_state = read_initial_state(states)
        accepting_states = read_accepting_states(states)
        transition_table = read_transition_table(states, alphabet)

        print_transition_table(alphabet, states, transition_table)
        repeat = run_verification(alphabet, transition_table, accepting_states, initial_state)


if __name__ == '__main__':
    main()

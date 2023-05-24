class RuleBasedChatbot:
    def __init__(self):
        self.rules = {
            'hi': 'Hello!',
            'how are you?': 'I am doing well, thank you!',
            'what is your name?': 'My name is Chatbot.',
            'who created you?': 'I was created by OpenAI.',
            'bye': 'Goodbye! Have a great day!'
            # Add more rules here
        }

    def start_chat(self):
        print("Chatbot: Hello! How can I assist you today?")
        while True:
            user_input = input("User: ")
            if user_input.lower() == 'exit':
                break
            self.generate_response(user_input)

    def generate_response(self, user_input):
        response = self.search_rules(user_input)
        if response:
            print("Chatbot:", response)
        else:
            print("Chatbot: I'm sorry, I don't understand.")

    def search_rules(self, user_input):
        for rule, response in self.rules.items():
            if rule in user_input.lower():
                return response
        return None

# Usage
chatbot = RuleBasedChatbot()
chatbot.start_chat()


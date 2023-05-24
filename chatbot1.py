from fuzzywuzzy import fuzz

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
        matched_rule = self.search_rules(user_input)
        if matched_rule:
            print("Chatbot:", self.rules[matched_rule])
        else:
            print("Chatbot: I'm sorry, I don't understand.")

    def search_rules(self, user_input):
        highest_similarity = 0
        matched_rule = None
        for rule in self.rules.keys():
            similarity = fuzz.ratio(user_input.lower(), rule.lower())
            if similarity > highest_similarity:
                highest_similarity = similarity
                matched_rule = rule
        return matched_rule if highest_similarity >= 70 else None

# Usage
chatbot = RuleBasedChatbot()
chatbot.start_chat()


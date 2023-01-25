

def apply_rule(rule, current_rule, total_word, words):
    if current_rule >= len(rule):
        str_tw = ''.join(total_word)
        return print(str_tw)
    if rule[current_rule] == '0':
        for i in range(10):
            total_word[current_rule] = str(i)
            apply_rule(rule, current_rule + 1, total_word, words)
    else:
        for i in words:
            total_word[current_rule] = i
            apply_rule(rule, current_rule + 1, total_word, words)


keep_running = True
while keep_running:
    try:
        n_words = int(input())
        words = []
        for i in range(n_words):
            words.append(input())
        n_rules = int(input())
        rules = []
        print("--")
        for i in range(n_rules):
            rules.append(input())
            total_word = [None]*(len(rules[i]))
            apply_rule(rules[i], 0, total_word, words)
    except EOFError as e:
        keep_running = False


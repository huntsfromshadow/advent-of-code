import re
import collections 

#FILE_NAME = "test-input.txt"
FILE_NAME = "day4-input.txt"

card_library = {}
total_cards = {}
starting_cards = []
last_card = 0

class Card():
    def __init__(self, gn, wnl, nl):
        self.card_number = gn
        self.winning_number_list = wnl
        self.number_list = nl

        result = collections.Counter(self.winning_number_list) & collections.Counter(self.number_list)
        inter_lst = list(result.elements())
        self.match_count = len(inter_lst)

def disp_total_cards():
    print("**********************")
    for key, value in total_cards.items():
        print(f"Card #{key}: {value}")

def walk_cards(theCard):
    #print(f"I'm in walk - theCard is {theCard}")
    # If it is bigger than last card bail
    if(theCard > last_card):
        print(f"\t{theCard} is not in the card list")
        return
    else:
        # Else here we have a valid card. Lets get it's steps
        total_cards[theCard] = total_cards[theCard] + 1
        c = card_library[theCard]
        #print( f"\tmatch count for {theCard} is {c.match_count}")

        if c.match_count == 0:
            print("\tReturning up 0 match")
            return
        else:
            to_walk = list(range(theCard + 1, theCard + 1 + c.match_count))
            print (f"\tWalk list is {to_walk}")
        
            for t in to_walk:
                #print("\t===================")
                walk_cards(t)



def main():
    lines = []
    f = open(FILE_NAME, "r")
    lines = f.readlines()
    
    # ---------------------

    r = re.compile(r"Card\s+(\d+): (.*) \| (.*)")
    for l in lines:
        l = l.strip("\n")
        m = r.search(l)

        print(l)
        cn = int(m.groups()[0])
        
        tl = m.groups()[1].split()
        wnl = [int(i) for i in tl]

        tl = m.groups()[2].split()
        nl = [int(i) for i in tl]

        card_library[cn] = Card(cn, wnl, nl)

        global last_card
        if(cn > last_card):
            last_card = cn

        starting_cards.append(cn)
        total_cards[cn] = 0

    # -----------------------------------------------------

    for x in starting_cards:
        walk_cards(x)
        

    disp_total_cards()
    
    total = 0
    for _, value in total_cards.items():
        total = total + value
    
    print(total)

    # total = 0
    #for key, value in card_library.items():
    #    print(f"CN {value.card_number} - {value.match_count}")
     
    # Process
    # print(unprocessed_cards)
    # print("======")
    # while len(unprocessed_cards) != 0:
    #     #print(unprocessed_cards)
    #     cid = unprocessed_cards.pop(0)
    #     if(cid < 10):
    #         print(f"Looking at {cid}   - len - {len(unprocessed_cards)}")
    #     elif(cid < 100):
    #         print(f"Looking at {cid}  - len - {len(unprocessed_cards)}")
    #     else:
    #         print(f"Looking at {cid} - len - {len(unprocessed_cards)}")

    #     total_count = total_count + 1

    #     mc = card_library[cid].match_count
    #     nr = list(range(cid+1, min(cid + 1 + mc, last_card )))
    #     unprocessed_cards.extend(nr)

    #     #print(unprocessed_cards)
    #     #print("-----")
        
        
    # print(f"Tota: {total_count}")
if __name__ == '__main__':
    main()

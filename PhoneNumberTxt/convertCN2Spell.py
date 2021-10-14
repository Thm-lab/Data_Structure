from xpinyin import Pinyin

def convertCN2Spell(ch):
    s = "".join(tuple(ch))
    p = Pinyin()
    StrSpell = p.get_initials(ch, '')
    return StrSpell
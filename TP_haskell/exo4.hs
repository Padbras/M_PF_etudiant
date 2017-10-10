-- 'Z' < 'a' retourne true (ASCII)

-- "abc" <= "ab" retourne false (plus long)

-- "abc" >= "ac" retourne false (comparaison point à point)

-- 1 + 2 * 3 retourne 7 (priorité opérateurs)

-- 5.0 - 4.2 / 2.1 retourne 3.0

-- 3 > 4 || 5 < 6 && not (7 /= 8) retourne false

-- if 6 < 10 then 6.0 else 10.0 retourne 6.0

---------------------------------------------------------------------------

-- 18 mod 7 / 2 mod et défini pour des entiers et 7/2 compte pour des float
-- de plus, mod étant une fonction, placé ainsi il faudra l'écrire `mod`

-- if 2 < 3 then 3 Il manque le else

-- 1 < 2 and 5 > 3 On ne met pas and mais &&

-- 6 + 7 div 2 On doit soit l'écrire autrement, soit mettre `div`

-- 4. + 3.5 Si on ne met pas 4.0 c'est pas le même type, ça marche pas

-- 1.0 < 2.0 or 3 > 4 Pas or mais ||

-- 1.0 = 3 Utiliser == pas =, et typage non valide entre les deux

-- if 4 > 4.5 then 3.0 else 'a' 'a' n'est pas un float du coup ça marche pas 

----------------------------------------------------------------------------

-- 2 < 1 bool

-- 4.2 + 2.0 doubme ou Fractional a=>a

-- 4.2 + 2 cf au dessus

-- 4 + 2 int ou Num a=>a

-- (4::Int) + 2 int

-- floor 2.3 int

-- fromIntegral 3 Fractional

-- succ 2.2

-- succ 2

-- succ (2::Int)

-- succ 'b'

-- show 2 String

-- show 2.4 String

----------------------------------------------------------------------------
--    [1,2,3] !! ([1,2,3] !! 1) retourne 3 (ordre 0,1,2)

--    head [1,2,3] retourne 1

--    tail [1,2,3] renvoie 2,3

--    "a":["b","c"] renvoie ["a","b","c"]

--    "abc" ++ "d" renvoie abcd

--    tail "abc" ++ "d" renvoie bcd

--    head "abc" : "d" renvoie ad

--    ([1,2,3] !! 2 : []) ++ [3,4] renvoie [3,3,4]

--    [3,2] ++ [1,2,3] !! head [1,2] : [] renvoie [3,2,2

----------------------------------------------------------------------------


--    head []
--    tail []
--    ["n"]:["o","n","!"] ici n ne doit pas être une liste
--    1 ++ 2 là c'est pas des listes donc la cocnat marche pas
--    head "abc" ++ "d" faut en faire une liste avant le ++

--------------------------------------------------------------------------



--    ['a', 'b', 'c'] [Char] ou String (meme combat)
--    ('a', 'b', 'c') (Char,Char,Char)
--    [(False, 0), (True, 1)]  [(Bool, Int)]
--    ([False, True], [0, 1]) ([Bool],[Int])
--    [tail, init, reverse] [[a]->[a]]
--    (1.5,("3",[4,5])) (Float, (String, [Int]))
--    [[1,2],[]] [[Int]]
--    (['a','b'],[[],[1,2,3]]) (String,[[Int]]) 



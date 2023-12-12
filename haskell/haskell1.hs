import Distribution.PackageDescription.Quirks (patchQuirks)
-- comment
-- ctr - `
-- :r
-- Int Float Double Bool
-- Char, Integer

x = 5

foo :: Int -> Int -> Int
foo x y = 2 * x + y

c :: Char
c = '?'

fib :: Integer -> Integer
fib n = if n < 2 then n else fib (n - 1) + fib (n - 2)

{-
fib2 :: Integer -> Integer
fib2 n
 | n == 0    = 0
 | n == 1    = 1
 | otherwise = fib2 (n - 1) + fib2 (n - 2)
-}

fib3 :: Integer -> Integer
fib3 0 = 0
fib3 1 = 1
fib3 n = fib3 (n - 1) + fib3 (n - 2)

fib2 :: Integer -> Integer
fib2 n = case 2 * n of 0 -> 0
                       1 -> 1
                       k -> fib2 (k - 1) + fib2 (k - 2)

complAdd :: (Num a, Num b) => (a, b) -> (a, b) -> (a, b)
complAdd p1 p2 = (x1+x2, y1+y2)
             where x1 = fst p1
                   y1 = snd p1
                   x2 = fst p2
                   y2 = snd p2

--fst snd 

--complAdd (x1,y1) (x2,y2) = (x1+x2, y1+y2)

flipPair :: (b, a) -> (a, b)
flipPair (x,y) = (y,x)

f :: Int -> Int -> Float
f x y = (fromIntegral x + fromIntegral y) / 2

myList :: [Int]
myList = [1,2,3]

length' :: [a] -> Int
length' = foldr (\ x -> (+) 1) 0

uniques lst = foldr (\ el res -> if elem el res then res else el:res) [] lst

sorted :: [Int] -> Bool
sorted lst = all (\p -> fst p <= snd p) pairs
      where pairs = zip lst (tail lst)

getDivisors n = [ x ^ 2 | x<-[2..n], mod n x == 0 ]

cartesian lst1 lst2 = [ (x,y) | x<-lst1, y<-lst2, x < y]
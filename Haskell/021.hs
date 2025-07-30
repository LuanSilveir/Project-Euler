import Data.Time

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  --putStrLn ("Solution: " ++ (show result))
  --putStrLn ("Execution Time: " ++ (show diffTime))
  putStrLn $ (reverse.tail.reverse) (show diffTime)

solution :: Int
solution = sum [x | x <- [2..9999], amicable x]

primeFactors :: Int -> Int -> [Int]
primeFactors 1 k = []
primeFactors n k = if n `mod` k == 0 then k : (primeFactors (n `div` k) k) else primeFactors n (k+1)

perms :: [Int] -> [[Int]]
perms []     = [[]]
perms (x:xs) = map (x:) p ++ p where p = perms xs 

uniques :: [Int] -> [Int]
uniques []     = []
uniques (x:xs) = x : filter (/=x) (uniques xs) 

properDivisors :: Int -> [Int]
properDivisors 1 = []
properDivisors n = tail $ uniques (map product (perms $ primeFactors n 2))

d :: Int -> Int
d = sum . properDivisors

amicable :: Int -> Bool
amicable n = n == d(s) && n /= s where s = d(n)

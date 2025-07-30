import Data.Time

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  putStrLn ("Solution: " ++ (show result))
  putStrLn ("Execution Time: " ++ (show diffTime))
  --putStrLn $ (reverse.tail.reverse) (show diffTime)

-- Solution
solution :: Int
solution = answer triangularNumbers

-- 3193.198316863 seconds solution (~53mins)
--divisors :: Int -> [Int]
--divisors n = [i | i <- [1..(n`div`2)+1], n `mod` i == 0] ++ [n]

-- Infinite list of triangular numbers
triangularNumbers :: [Int]
triangularNumbers = [sum [1..n] | n <- [1..]]

-- All possible choices of [0..k] elements from a list 
-- Choosing k elements from a list is the list where the head (x) was chosen united with the list where it wasn't
choices []     k = [[]]
choices _      0 = [[]]
choices (x:xs) k = (map (x:) (choices xs (k-1))) ++ (choices xs k)

-- Unique elements in a list
uniques :: Eq a => [a] -> [a]
uniques [] = []
uniques (x:xs) = x : uniques (filter (/=x) xs)

-- Recursive function for all prime factors of 'n'
factors :: Int -> Int -> [Int] -> [Int]
factors 1 _ xs = xs
factors n k xs = if n `mod` k == 0 then factors (n `div` k) k (k:xs) else factors n (k+1) xs               

-- Prime factors of a number 'n' (Just a convenience function to not pass all arguments of 'factors'
primeFactors :: Int -> [Int]
primeFactors n = factors n 2 []

-- Divisors of a number 'n'
divisors :: Int -> [Int]
divisors n = uniques (map product (choices (pf) (length pf))) where pf = primeFactors n

-- Function to find the first number in a list with more than 500 divisors
answer :: [Int] -> Int
answer [] = -1
answer (t:ts) = if (length.divisors) t >= 500 then t else answer ts
  


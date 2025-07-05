import Data.Time

main :: IO ()
main = do 
  startTime <- getCurrentTime
  let result = solution
  endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  putStrLn ("Solution: " ++ (show result))
  putStrLn ("Execution Time: " ++ (show diffTime))

solution :: Int
solution = largestPrime (factors 600851475143 2 [])


factors :: Int -> Int -> [Int] -> [Int]
factors 1 _ fs = fs 
factors n k fs = if n `mod` k == 0 then factors (n `div` k) k (k:fs) else factors n (k+1) fs

isPrime :: Int -> Bool
isPrime n = length (factors n 2 []) == 1

largestPrime :: [Int] -> Int
largestPrime [] = -1
largestPrime (x:xs) = if isPrime x then x else largestPrime xs

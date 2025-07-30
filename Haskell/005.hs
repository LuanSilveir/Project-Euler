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

solution :: Int
solution = product (fac 20)

factors :: Int -> Int -> [Int] -> [Int]
factors 1 _ fs = fs 
factors n k fs = if n `mod` k == 0 then factors (n `div` k) k (k:fs) else factors n (k+1) fs
 
isPrime :: Int -> Bool
isPrime n = length (factors n 2 []) == 1

primes :: Int -> [Int]
primes n = [p | p <- [2..n], isPrime p]

biggestPower :: Int -> Int -> Int
biggestPower n k = if k >= n then (round $ sqrt $ fromIntegral k) else biggestPower n (k*k)

fac :: Int -> [Int]
fac n = map (biggestPower n) (primes n)

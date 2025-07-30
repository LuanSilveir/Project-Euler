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
solution = (squareSum 100) - (sumSquares 100)

sumSquares :: Int -> Int
sumSquares n = sum [i*i | i <- [1..n]]

squareSum :: Int -> Int
squareSum n = (sum [1..n])^2


